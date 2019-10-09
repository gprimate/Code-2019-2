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
SELECT m.movie_name

FROM m.movie (
    (SELECT *
    FROM movie m NATURAL JOIN role r NATURAL JOIN role_type rt
    WHERE rt.type_name='director') 

    NATURAL JOIN

    (SELECT *
    FROM person p 
    WHERE p.person_name='Lucas, George') 
) 

SELECT movie_name

FROM movie 

WHERE movie_name in 
    ((SELECT m.movie_name
    FROM movie m NATURAL JOIN role r NATURAL JOIN role_type rt
    WHERE rt.type_name='director') 

    NATURAL JOIN

    (SELECT role_type_id
    FROM person p 
    WHERE p.person_name='Lucas, George'))
 
SELECT p.person_name
FROM person p NATURAL JOIN role r NATURAL JOIN movie m
WHERE m.movie_name='Alien' AND p.gender='f'



-------------------------
-------------------------
-- Parte 2

--3)

SELECT p.person_name, COUNT(r.person_id)
FROM person p NATURAL JOIN role r  NATURAL JOIN role_type rt
WHERE rt.type_name='actor'
GROUP BY p.person_name
ORDER BY COUNT(r.person_id) DESC
LIMIT 1


--4)

SELECT m.movie_name, p.person_name
FROM person p NATURAL JOIN role r NATURAL JOIN movie m NATURAL JOIN role_type rt
WHERE rt.type_name='director' AND p.gender='f'


--5)--pm.person_name, pf.person_name WHERE rtm.type_name='actor' AND rtf.type_name='actress'
SELECT pm.person_name, pf.person_name, COUNT(rm.person_id)
FROM (person pm NATURAL JOIN role rm NATURAL JOIN role_type rtm), (person pf NATURAL JOIN role rf NATURAL JOIN role_type rtf)
WHERE rtm.type_name='actor' AND rtf.type_name='actress' AND rm.movie_id = rf.movie_id
GROUP BY pm.person_name, pf.person_name
ORDER BY COUNT(rm.person_id) DESC
LIMIT 1


--6)

SELECT *
FROM  role r NATURAL JOIN movie m NATURAL JOIN role_type rt
WHERE m.movie_name='Persona'


--7)

SELECT p.person_name, COUNT(m.movie_id), AVG(m.rating)
FROM person p NATURAL JOIN role r NATURAL JOIN movie m NATURAL JOIN role_type rt
WHERE rt.type_name='director'
GROUP BY p.person_name
HAVING COUNT(m.movie_id) > 2
ORDER BY AVG(m.rating) DESC
LIMIT 7