#ifndef __INCLUDE_UNIQUE_ID_REGISTER_TYPE_H
#define __INCLUDE_UNIQUE_ID_REGISTER_TYPE_H
#include <cstdint>
/*
    C++11 后提供了enum class，一个是枚举值作用域限定，不再如果#define或者enum是全局的，容易导致命名冲突，
    另一方面不再可以隐式转换成整数，减少了意外行为的可能性。
    c++14 后通过使用enum关键字，可以实现enumclass的自增。
*/

/*
    新增模块类型直接在enum class 中添加枚举值即可
*/

enum class UNIQUEID_REGISTER_TYPE : uint8_t{
    UNIQUEID_REGISTER_TYPE_DEFAULT,
    UNIQUEID_REGISTER_TYPE_TEST,
    UNIQUEID_REGISTER_TYPE_MAX
};



#endif
