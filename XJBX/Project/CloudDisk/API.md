## 接口简介

### 1 注册

注册是一个简单的  HTTP 接口，根据用户输入的注册信息，创建一个新的用户。

请求URL

| URL          | http://192.168.52.139/reg |
| ------------ | ------------------------- |
| 请求方式     | POST                      |
| HTTP 版本    | 1.1                       |
| Content-Type | application/json          |

请求参数

| 参数     | 意义     | 规则                         |
| -------- | -------- | ---------------------------- |
| email    |          | 符合规范，但实际没有加入检测 |
| fistPwd  | 密码     | md5之后的密码                |
| nickName | 用户昵称 | 不能超过32char               |
| phone    |          | 16字符以内                   |
| userName | 用户名   | 不能超过32char               |

返回

| 名称 | 说明                                    |
| ---- | --------------------------------------- |
| code | 002：成功，003：用户名已存在；004：失败 |

实例

```
http://192.168.52.139/reg
```

参数

```
{
"email": "472251823@qq.com",
"firstPwd": "e10adc3949ba59abbe56e057f20f883e", "nickName": "milo",
"phone": "18620823143", "userName": "milo"
}
```

返回

```
{	
	"code":    "002"
}
```

### 2 login

请求 URL

| URL          | http://192.168.52.139/login |
| ------------ | --------------------------- |
| 请求方式     | POST                        |
| HTTP 版本    | 1.1                         |
| Content-Type | application/json            |

参数

| pwd  | md5之后的密码        |
| ---- | -------------------- |
| user | 不能超过32char的用户 |

返回

| 名称  | 说明                                                         |
| ----- | ------------------------------------------------------------ |
| code  | 000：成功；001：失败                                         |
| token | 每次登录之后生成的token都不一样，后续其他请求的时候要带上token |

实例

```
http://192.168.52.139/login
```

参数

```
{
"pwd": "e10adc3949ba59abbe56e057f20f883e", 
"user": "milo"
}
```

返回

```
{
"code":    "000",
"token": "ecf3ac6f8863cd17ed1d3909c4386684"
}
```

### 3 获取文件数量

| URL          | http://192.168.52.139/myfiles?cmd=normal |
| ------------ | ---------------------------------------- |
| 请求方式     | POST                                     |
| HTTP 版本    | 1.1                                      |
| Content-Type | application/json                         |

参数

| 参数  | 意义       | 规则  |
| ----- | ---------- | ----- |
| token |            |       |
| user  | 密码       |       |
| count | 文件数     | 大于0 |
| start | 开始的位置 |       |

返回

| 名称  | 规则                                                         |
| ----- | ------------------------------------------------------------ |
| files | user:用户名，MD5，md5值，create_time，创建时间，file_name,文件名。。。。 |

实例

```
http://192.168.52.139/myfiles?cmd=normal
```

参数

```
{
"count": 1, "start": 0,
"token": "ecf3ac6f8863cd17ed1d3909c4386684", "user": "milo"
}
```

返回

```
{
"files":   [{
"user":    "milo",
"md5":     "602fdf30db2aacf517badf4565124f51",
"create_time":        "2020-07-03 20:37:18",
"file_name":          "Makefile",
"share_status":       0,
"pv":      0,
"url": "http://172.16.0.15:80/group1/M00/00/00/rBAAD17_Jn6AM-iuAACBBC5AIsc2532509",
"size":    33028,
"type":    "null"
}] }
```

### 4 删除文件

| URL          | http://192.168.52.139/dealfile?cmd=del |
| ------------ | -------------------------------------- |
| 请求方式     | POST                                   |
| HTTP 版本    | 1.1                                    |
| Content-Type | application/json                       |

请求参数

| 参数     | 详细    |
| -------- | ------- |
| token    | 令牌    |
| user     | 32 char |
| md5      | 加密    |
| filename | 文件名  |

返回

| 名称 | 说明               |
| ---- | ------------------ |
| code | 013 成功，004 失败 |

还有接口的是实现和详细参阅代码
