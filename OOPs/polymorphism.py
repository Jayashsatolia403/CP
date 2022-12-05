class Polymorphism:
    def __init__(self) -> None:
        self.name = "Jayash"

    def gn(self, name=""):
        print(self.name)
        if name:
            print(name, end = "\n\n")
        else:
            print(self.name, end = "\n\n")


class Game():
    def __init__(self) -> None:
        self.f = "Gen"
    
    def check(self):
        print(self.f)

class Chess(Game):
    def __init__(self) -> None:
        pass

    def check(self):
        print(Game.f)


c = Chess()
g = Game()


c.check()
g.check()
# print(g.name)

# p = Polymorphism()

# p.gn()
# p.gn("Hermoine")