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

### 单机效果

| 方式                   | 每秒执行次数   |
| ---------------------- | -------------- |
| 每次分配1个UniqueID    | 55555000 次/秒 |
| 每次分配1000个UniqueID | 24236000 次/秒 |

- 在单机情况下应该可以满足绝大多数需求。
