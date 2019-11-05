/* Questão 1 */

soma([], 0).
soma([A|B], N):-
    sum(B, X),
    N is X + A.


/* Questão 2 */

prefixo(X, Y) :-
    X = [_|_],
    Rest = [_|_],
    append(X, Rest, Y).


/* Questão 3 */

sufixo(Y, X) :-
    Front = [_|_],
    X = [_|_],
    append(Front, X, Y).



/* Questão 4 */

sublista([], _).
sublista([A|X], [A|Y]) :- sublista(X, Y).
sublista([A|X], [_|Y]) :- sublista([A|X], Y).


/* Questão 5 */

subsequencia(Y, X) :-
   Y = [_|_],           
   append(_, Z, X),    
   append(Y, _, Z).


/* Questão 6 */

particiona(H, [A|X], [A|Y], Z) :-
    order(A, H), particiona(H, X, Y, Z).
particiona(H, [A|X], Y, [A|Z]) :-
    not(order(A, H)), particiona(H, X, Y, Z).
particiona(_, [], [], []).
