import rpcServer

def add(a,b,c = 10):
    sum = a + b + c
    return sum



if __name__ == "__main__":
    s = rpcServer.rpcServer()
    s.register_func(add)
    s.loop(5000)
