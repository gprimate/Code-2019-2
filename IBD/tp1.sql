-- Parte 1 --

-- 1)

SELECT movie_name, genre_name 
FROM ((movie NATURAL JOIN movie_info) NATURAL JOIN movie_genre) 
WHERE movie_name = 'Pulp Fiction'


-- 2) ainda errada

SELECT M.movie_name
FROM (
    ((SELECT * 
    FROM ((role_type NATURAL JOIN role) NATURAL JOIN movie) AS L
    WHERE L.type_name='director')

    NATURAL JOIN 

    (SELECT * 
    FROM person as T
    WHERE T.person_name='Lucas, George'))
) AS M

----------------------------------- certa

SELECT m.movie_name
FROM movie m NATURAL JOIN role r NATURAL JOIN role_type rt NATURAL JOIN person p
WHERE rt.type_name='director' AND p.person_name='Lucas, George'

-- 3) Certa

SELECT movie_name, production_year, rating
FROM movie
WHERE ranking='1'


-- 4) nao testada

(SELECT person_name
    FROM (
        person NATURAL JOIN (
            SELECT *
            FROM (movie NATURAL JOIN role)
            WHERE movie_name = 'Alien'
        )
    )
)

INTERSECT

(SELECT person_name
FROM person 
WHERE gender = 'f'
)
----------------------------- certa

SELECT p.person_name
FROM person p NATURAL JOIN role r NATURAL JOIN movie m
WHERE m.movie_name='Alien' AND p.gender='f'



-- 5) nao testada

(SELECT person_name
FROM (
    person NATURAL JOIN (
        SELECT *
        FROM (movie NATURAL JOIN role)
        WHERE movie_name = 'Alien'
    )
))

UNION

(SELECT person_name
FROM person 
WHERE gender = 'f'
)

---------------------------- certa
(SELECT p.person_name
FROM person p NATURAL JOIN role r NATURAL JOIN movie m
WHERE m.movie_name='Alien')

UNION

(SELECT person_name
FROM person 
WHERE gender = 'f')



-------------------------------------------------------------------------------
select p.person_name, r.role_name 
from movie m natural join role r natural join person p 
where m.movie_name = 'The Lord of the Rings: The Fellowship of the Ring';

SELECT m.movie_name
FROM movie m NATURAL JOIN role r NATURAL JOIN role_type rt
WHERE rt.type_name='director'

NATURAL JOIN

SELECT *
FROM person p 
WHERE p.person_name='Lucas, George'

-------------------------------------------------------------------------------
SELECT total.movie_name

FROM (
    (SELECT *
    FROM movie m NATURAL JOIN role r NATURAL JOIN role_type rt
    WHERE rt.type_name='director') 

    NATURAL JOIN

    (SELECT *
    FROM person p 
    WHERE p.person_name='Lucas, George') 
) total




