#include "UniqueID_recv.h"
#include "UniqueID_api.h"
#include "uniqueid_register_type.h"
#include <vector>

typedef int (*send_to_client)(uint64_t, void* msg);

int send_to_client(uint64_t, void* msg)
{
    return 0;
}

class MessageRsp{};

int uniqueid_recv_single_id_req(uint64_t id_from, uint64_t src_addr, MessageSingle* req)
{
    UNIQUEID_REGISTER_TYPE register_type = static_cast<UNIQUEID_REGISTER_TYPE>(req->register_type);
    uint64_t free_id = Free_ID_Alloc(register_type);

    MessageRsp rsp;
    // 需要提供send_to_client的实现
    return send_to_client(id_from, &rsp); 
}

int uniqueid_recv_batch_id_req(uint64_t id_from, uint64_t src_addr, MessageBatch* req)
{
    UNIQUEID_REGISTER_TYPE register_type = static_cast<UNIQUEID_REGISTER_TYPE>(req->register_type);   
    uint32_t alloc_num = req->alloc_num;

    std::vector<uint64_t> free_id_array = Free_ID_Alloc(register_type, alloc_num);

    MessageRsp rsp;
    // 需要提供send_to_client的实现
    return send_to_client(id_from, &rsp);     

}