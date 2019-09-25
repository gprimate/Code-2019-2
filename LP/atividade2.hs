type Nome   = String
type Idade  = Integer
type RG     = String

data Pessoa = Pessoa {nome::Nome, idade::Idade, id::RG}
    deriving(Show)

gui = Pessoa "Gui" 25 "20"
gui2 = Pessoa "Gui" 26 "20"
gui3 = Pessoa "Gui" 27 "20"
gui4 = Pessoa "Gui" 28 "20"

lista = [gui,gui2,gui3,gui4]

-- Questão 2
somaIdade :: [Pessoa] -> Integer
somaIdade = foldr ((+) . idade) 0 

-- Questão 3
minimo :: [Pessoa] -> String
minimo = foldr ((. idade) min a x) . nome)

-- Questão 4
import Data.Char
import Data.Typeable

maiusc :: [String] -> String
maiusc = foldr((:) . isInteger)

-- Questão 6
remdups :: a => [a] -> [a]
remdups [] = []
remdups (y:ys) = foldr [y] ys

-- Questão 7
contaAdjs:: Ord a => [a] -> [(Int,a)]
contaAdjs = foldr (||) False . map (x ==)