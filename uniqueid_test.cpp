#include "UniqueID_api.h"
#include "uniqueid_register_type.h"
#include <chrono>
#include <iostream>

void SingleIDAlloc()
{
    // 1s 可以分配多少ID 单线程
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 1000000; ++i)
    {
        Free_ID_Alloc(UNIQUEID_REGISTER_TYPE::UNIQUEID_REGISTER_TYPE_TEST);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Function executed " << 1000000 << " times in " << duration.count() << " milliseconds." << std::endl;

    int executionsPerSecond = 1000000 / duration.count() ;
    std::cout << "The function was executed approximately " << executionsPerSecond << " times per milliseconds." << std::endl;

}

void MultipleIDAlloc()
{
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 1000; i++)
    {
        Free_ID_Alloc(UNIQUEID_REGISTER_TYPE::UNIQUEID_REGISTER_TYPE_TEST, 100000);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Function executed " << 100000000 << " times in " << duration.count() << " milliseconds." << std::endl;

    int executionsPerSecond = 100000000 / duration.count() ;
    std::cout << "The function was executed approximately " << executionsPerSecond << " times per milliseconds." << std::endl;



}

int main()
{
    // 测试 单独分配ID的性能
    SingleIDAlloc();

    // 测试 分配一组ID的性能
    MultipleIDAlloc();
}