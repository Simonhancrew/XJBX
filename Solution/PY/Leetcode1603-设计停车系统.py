class ParkingSystem:

    def __init__(self, big: int, medium: int, small: int):
        self.big,self.mediu,self.small = big,medium,small

    def addCar(self, carType: int) -> bool:
        if carType == 1:
            if(self.big > 0):
                self.big -= 1
                return True
        elif carType == 2:
            if self.mediu > 0:
                self.mediu -= 1
                return True
        else:
            if self.small > 0:
                self.small -= 1
                return True
        return False

