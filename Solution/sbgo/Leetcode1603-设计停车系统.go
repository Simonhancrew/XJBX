package sbgo

type ParkingSystem struct {
	big, medium, small int
}

func Constructor(big int, medium int, small int) ParkingSystem {
	return ParkingSystem{big: big, medium: medium, small: small}
}

func (this *ParkingSystem) AddCar(carType int) bool {
	if carType == 1 {
		if this.big > 0 {
			this.big--
			return true
		}
	} else if carType == 2 {
		if this.medium > 0 {
			this.medium--
			return true
		}
	} else {
		if this.small > 0 {
			this.small--
			return true
		}
	}
	return false
}
