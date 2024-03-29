#ifndef __INCLUDE_UNIQUEID_API_H
#define __INCLUDE_UNIQUEID_API_H
#include <cstdint>
#include <vector>
#include "uniqueid_register_type.h"

// alloc one unique ID according to register_type
const uint64_t Free_ID_Alloc(UNIQUEID_REGISTER_TYPE Register_Type);
const std::vector<uint64_t> Free_ID_Alloc(UNIQUEID_REGISTER_TYPE Register_Type, int32_t alloc_num);

// Distributed system
const uint64_t Distributed_Free_ID_Alloc(UNIQUEID_REGISTER_TYPE register_type);
const std::vector<uint64_t> Distributed_Free_ID_Alloc(UNIQUEID_REGISTER_TYPE register_type, int32_t alloc_num);


#endif