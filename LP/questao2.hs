data Pessoa = Pessoa {nome::Nome, idade::Idade, id::RG}
    deriving(Show)
type Nome   = String
type Idade  = Integer
type RG     = String

gui = Pessoa "Gui" 25 "20"
gui2 = Pessoa "Gui" 26 "20"
gui3 = Pessoa "Gui" 27 "20"
gui4 = Pessoa "Gui" 28 "20"

banana = [gui,gui2,gui3,gui4]

somaIdade :: Pessoa -> Int
somaIdade = foldr (+) 0 []