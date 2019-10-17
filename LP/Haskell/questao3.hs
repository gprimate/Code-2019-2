type Nome   = String
type Idade  = Integer
type RG     = String
data Pessoa = Pessoa {nome::Nome, idade::Idade, id::RG}
    deriving(Show)

