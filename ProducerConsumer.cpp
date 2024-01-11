#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>
#include <unistd.h>

template <typename T>
class ProduceConsumeQueue {
public:
	ProduceConsumeQueue(uint32_t size) : sz_(size) {}

	void Produce(const T& data) {
		std::unique_lock<std::mutex> ulock(lock_);

		produce_cond_.wait(ulock, [this]() {
			return this->queue_.size() < sz_;
		});

		queue_.push(data);
		std::cout << "produce: " << data << std::endl;

		consume_cond_.notify_one();
	}

	T Consume() {
		std::unique_lock<std::mutex> ulock(lock_);

		consume_cond_.wait(ulock, [this]() {
			return !queue_.empty();
		});

		auto data = queue_.front();
		queue_.pop();

		std::cout << "consume: " << data << std::endl;

		produce_cond_.notify_one();
		return data;
	}

private:
	std::mutex lock_;
	std::condition_variable produce_cond_;
	std::condition_variable consume_cond_;

	uint32_t sz_{0};
	std::queue<T> queue_;
};

class Producer {
public:
	Producer() = default;

	void Init(std::shared_ptr<ProduceConsumeQueue<int> >& queue) {
		queue_ = queue;
	}

	void Produce() {
		int i = 0;
		while (true) {
			sleep(1);
			queue_->Produce(i++);
		}
	}

private:
	std::shared_ptr<ProduceConsumeQueue<int> > queue_;
};

class Consumer {
public:
	Consumer() = default;

	void Init(std::shared_ptr<ProduceConsumeQueue<int> >& queue) {
		queue_ = queue;
	}

	void Consume() {
		while (true) {
			auto val = queue_->Consume();
		}
	}

private:
	std::shared_ptr<ProduceConsumeQueue<int> > queue_;
};


int main() {
	auto pc_queue = std::make_shared<ProduceConsumeQueue<int> >(3);

	std::vector<Producer> producers(3);
	std::vector<Consumer> consumers(3);

	std::vector<std::thread> pthreads;
	std::vector<std::thread> cthreads;

	for (auto& p : producers) {
		p.Init(pc_queue);
		pthreads.emplace_back(std::thread(&Producer::Produce, &p));
	}

	for (auto& c : consumers) {
		c.Init(pc_queue);
		cthreads.emplace_back(std::thread(&Consumer::Consume, &c));
	}

	// join
	pause();

	return 0;
}
