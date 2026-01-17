#include <iostream>
#include <stdio.h>
#include <string>
#include <thread>

/// 
void thread1() {
	printf("thread1\n");
}

void thread2() {
	printf("thread2\n");
}

void thread3() {
	printf("thread3\n");
}

int main() {
	
	std::thread t1(thread1);
	t1.join();
	std::thread t2(thread2);
	t2.join();
	std::thread t3(thread3);
	t3.join();



	return 0;
}
