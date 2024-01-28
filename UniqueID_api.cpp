#include <UniqueID_api.h>
#include <atomic>
#include <ctime>
#include <mutex>

std::atomic<uint32_t> sequenceCounter(0);
std::mutex sequenceMutex; //用于同步访问的互斥锁

void resetSequenceCounter(){
    std::lock_guard<std::mutex> lock(sequenceMutex); //获取互斥锁
    sequenceCounter.store(0); //重置计数器为0
}


//UUID struct
struct CustomUUID{
    uint8_t register_type; //前8位，注册码
    uint32_t timestamp;    //中间32位，时间戳
    uint32_t sequence;     //后24位， 序列值

    static CustomUUID GenerateUUID(UNIQUEID_REGISTER_TYPE Register_type){
        CustomUUID uuid;

        // register_type 
        uuid.register_type = static_cast<uint8_t>(Register_type);

        // 获取当前时间戳
        uint32_t cur_timestamp = static_cast<uint32_t>(time(nullptr));

        // 获取当前序列值，这里使用原子操作包保证线程安全
        uint32_t sequence_val = ++sequenceCounter;
        if(sequence_val > 0xFFFFFF)
        {
            //SequenceCounter 超出24位 重置
            resetSequenceCounter();
            sequence_val = ++sequenceCounter;
        }
        uuid.sequence = sequence_val & 0xFFFFFFF; //Sequence 只保留24位

        return uuid;
    }

    uint64_t ToUint64() const {
        uint64_t uuidValue = (static_cast<uint64_t>(register_type) << 56) |
                             (static_cast<uint64_t>(timestamp) << 24)     |
                             (static_cast<uint64_t>(sequence));
        return uuidValue;   
    }
};



const uint64_t Free_ID_Alloc(UNIQUEID_REGISTER_TYPE Register_Type)
{
    auto freeid = CustomUUID::GenerateUUID(Register_Type);
    return freeid.ToUint64();
};

const std::vector<uint64_t> Free_ID_Alloc(UNIQUEID_REGISTER_TYPE Register_Type, int32_t alloc_num)
{
    std::vector<uint64_t> ans;
    for(int idx = 0; idx < alloc_num; ++idx)
    {
        auto freeid = CustomUUID::GenerateUUID(Register_Type);
        ans.push_back(freeid.ToUint64());
    }
    return ans;
};