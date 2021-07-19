import rpcClient

if __name__=="__main__":
    c = rpcClient.RPCclient()
    c.connect('127.0.0.1',5000)
    res = c.add(1,2,c = 3)
    print(res)
