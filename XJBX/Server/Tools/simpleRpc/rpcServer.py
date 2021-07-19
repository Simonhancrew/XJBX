import socket
import json


class TcpServer():
    def __init__(self):
        self.sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

    def bind_listend(self,port):
        self.sock.bind(('127.0.0.1',port))
        self.sock.listen(5)

    def accept_receive_close(self):
        (client_socket,address) = self.sock.accept()
        msg = client_socket.recv(1024)
        data = self.on_msg(msg)
        client_socket.sendall(data)
        client_socket.close()

class JsonParse():
    def __init__(self):
        self.data = None

    def from_data(self,data:json):
        self.data = json.loads(data.decode('utf-8'))

    def call_method(self,data):
        self.from_data(data)
        method_name = self.data['method_name']
        method_args = self.data['method_args']
        method_kwargs = self.data['method_kwargs']

        res = self.funs[method_name](*method_args,**method_kwargs)

        data = {'res':res}
        return json.dumps(data).encode('utf-8')

class rpcStub():
    def __init__(self):
        self.funs = {}

    def register_func(self,function,name = None):
        if name is None:
            name = function.__name__
        self.funs[name] = function


class rpcServer(TcpServer,JsonParse,rpcStub):
    def __init__(self):
        TcpServer.__init__(self)
        JsonParse.__init__(self)
        rpcStub.__init__(self)

    def loop(self,port):
        self.bind_listend(port)
        while True:
            self.accept_receive_close()

    def on_msg(self,data):
        return self.call_method(data)