intersect([],[],[]).
intersect(X,[],X).
intersect([head|tail], X, [head|Res]) :-
    member(head, X),
    inter(tail, X, Res).
intersect([_|tail], X, Res) :-
    inter(tail, X, Res).