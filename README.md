# UniqueID

- 本分支实现了一个单点的，本地的UniqueID分配库。
- UniqueID 自定义结构如下

```
struct CustomUUID{
    uint8_t register_type; //前8位，注册码
    uint32_t timestamp;    //中间32位，时间戳
    uint32_t sequence;     //后24位， 序列值
}
```

- register_type定义在uniqueid_register_type中
