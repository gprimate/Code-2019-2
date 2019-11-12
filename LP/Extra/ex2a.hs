uni([],[],[]).
uni(X,[],X).
uni(X, [head|tail], [head|Z]):-
    \+(member(head,X)), uni(X,tail,Z).
uni(X, [head|tail], Z):-
    member(head,X), uni(X,tail,Z). 