class Basket:
    basketId = 0
    apples = []
    heaviestAppleId = ""
    def __init__(self, basketId, apples) -> None:
        self.basketId = basketId
        for i in range(0, len(apples)):
            if (apples[i].basketId == self.basketId):
                self.apples.append(apples[i])

    def selectHeaviest(self):
        for i in range(0, len(self.apples)):
            if (self.apples[i].weight > self.heaviestApple.weight):
                self.heaviestAppleId = self.apples[i].appleId
                heaviestApple = self.apples[i]
        return heaviestApple
                
class Apple():
    basketId = 0
    appleId = ""
    weight = 0
    diameter = 0
    def __init__(self, basketId, appleId, weight, diameter) -> None:
        self.basketId = basketId
        self.appleId = appleId
        self.weight = weight
        self.diameter = diameter

    def show(self):
        print(self.appleId," ")
        print(self.weight,"" )
        print(self.diameter)

    def appleId(self):
        return self.appleId

appleNum = int(input())
baskets = []
apples = []

for i in range(0,appleNum):
    basketId, appleId, weight, diameter = map(str,input().split(' '))
    apples.append(Apple(int(basketId), appleId, int(weight), int(diameter)) )

for i in range(1,1000000):
    baskets.append(Basket(i, apples))
    Heaviest = baskets[i - 1].selectHeaviest()
    Heaviest.show()
    

