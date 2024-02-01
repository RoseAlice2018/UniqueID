#ifndef __INCLUDE_UNIQUEID_RECV_H_
#define __INCLUDE_UNIQUEID_RECV_H_

#include <cstdint>

/*
    这里的Message类仅仅作为示例，真实使用的时候可以根据选定的协议类型来决定Message类型，比如Protobuf等
*/

class MessageSingle
{
    public:
        uint8_t register_type;
};

class MessageBatch
{
    public:
        uint8_t register_type;
        uint32_t alloc_num;
};


int uniqueid_recv_single_id_req(uint64_t id_from, uint64_t src_addr, MessageSingle* req);

int uniqueid_recv_batch_id_req(uint64_t id_from, uint64_t src_addr, MessageBatch* req);

#endif