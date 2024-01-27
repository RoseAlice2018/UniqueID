#ifndef __INCLUDE_UNIQUEID_API_H
#define __INCLUDE_UNIQUEID_API_H
#include <cstdint>
#include <vector>

// alloc one unique ID according to register_type
uint64_t Free_ID_Alloc(int32_t Register_Type);
std::vector<uint64_t> Free_ID_Alloc(int32_t Register_Type, int32_t alloc_num);


#endif