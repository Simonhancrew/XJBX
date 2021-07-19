import socket
import json




class TCPclient():
    def __init__(self):
        self.socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

    def connect(self,host,port):
        self.socket.connect((host,port))

    def send(self,data):
        self.socket.send(data)

    def recv(self,length):
        return self.socket.recv(length)


class RPCstub():
    def __getattr__(self, function):
        def _func(*args,**kwargs):
            d = {
                "method_name":function,
                'method_args':args,
                'method_kwargs':kwargs,
            }
            self.send(json.dumps(d).encode('utf-8'))
            data = self.recv(1024)
            return data
        setattr(self,function,_func)
        return _func


class RPCclient(TCPclient,RPCstub):
    pass