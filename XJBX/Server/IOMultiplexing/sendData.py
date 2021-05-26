import socket


if __name__=="__main__":
    s = socket.socket()
    host = "192.168.31.40"   ##srv的ip 
    port = 8090              ##srv的port
    s.connect((host,port))
    buff = ""
    for i in range(1024):
        buff += '-'
    s.send(bytes(buff,encoding='gbk'))
    s.close()

