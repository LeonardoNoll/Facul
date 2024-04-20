--EX 2.1
SELECT c.nome_curso, nome_disciplina 
FROM curso c INNER JOIN disciplina d
ON c.id_curso = d.id_curso;

--EX 2.2
SELECT p.nome_professor, nome_area
FROM professor p INNER JOIN area a
ON p.id_area = a.id_area;

--EX 2.3
SELECT t.id_turma, t.semestre, a.nome_aluno, ta.media_final
FROM turma t INNER JOIN turma_aluno ta
ON t.id_turma = ta.id_turma
INNER JOIN aluno a
ON ta.id_aluno = a.id_aluno;

--EX 2.4
SELECT a.nome_aluno, c.nome_curso
FROM aluno a INNER JOIN aluno_curso ac
ON a.id_aluno = ac.id_aluno
INNER JOIN curso c
ON ac.id_curso = c.id_curso
WHERE ac.data_fim is not null;

--EX 2.5
SELECT t.id_turma, d.nome_disciplina, p.nome_professor
FROM turma t INNER JOIN disciplina d
ON t.id_disciplina = d.id_disciplina
INNER JOIN professor p
ON t.id_professor = p.id_professor;

--EX 2.6
SELECT d.nome_disciplina, ta.media_final
FROM disciplina d INNER JOIN turma t
ON d.id_disciplina = t.id_disciplina
INNER JOIN turma_aluno ta 
ON t.id_turma = ta.id_turma
INNER JOIN aluno a
ON ta.id_aluno = a.id_aluno
WHERE a.nome_aluno = 'Bruno' and t.semestre = '2018/1';

--EX 2.7
SELECT a.nome_aluno
FROM aluno a INNER JOIN turma_aluno ta
ON a.id_aluno = ta.id_aluno
INNER JOIN turma t 
ON ta.id_turma = t.id_turma
WHERE t.id_disciplina = 100 
AND ta.media_final >= 7 
AND t.semestre = '2018/1';

--EX 2.8
SELECT count(ta.id_aluno)
FROM turma_aluno ta INNER JOIN turma t
ON ta.id_turma = t.id_turma
WHERE t.semestre = '2018/1'
GROUP BY t.id_turma;

--EX 2.9
SELECT (sum(ta.media_final)/count(ta.media_final))
FROM turma t INNER JOIN turma_aluno ta 
ON t.id_turma = ta.id_turma
WHERE t.id_disciplina = 100
AND t.semestre = '2018/1'
GROUP BY ta.id_turma;

--EX 2.10
SELECT t.id_turma, d.nome_disciplina, count(id_aluno)
FROM turma t INNER JOIN disciplina d
ON t.id_disciplina = d.id_disciplina
LEFT OUTER JOIN turma_aluno ta
ON t.id_turma = ta.id_turma 
WHERE t.semestre = '2018/1'
GROUP BY t.id_turma, d.nome_disciplina;

--EX 2.11
SELECT t.id_turma, d.nome_disciplina
FROM turma t INNER JOIN disciplina d 
ON t.id_disciplina = d.id_disciplina
INNER JOIN turma_aluno ta
ON t.id_turma = ta.id_turma
WHERE t.semestre = '2018/1'
GROUP BY t.id_turma, d.nome_disciplina
HAVING count(*) > 30;

--EX 2.12 - ERRADO
SELECT A.NOME_AREA, COUNT(*)
FROM AREA A LEFT OUTER JOIN CURSO C
ON A.ID_AREA = C.ID_AREA
GROUP BY A.NOME_AREA;

--EX 2.12 - CERTO
SELECT A.NOME_AREA, COUNT(C.ID_CURSO)
FROM AREA A LEFT OUTER JOIN CURSO C
ON A.ID_AREA = C.ID_AREA
GROUP BY A.NOME_AREA;

--EX 2.13
SELECT P.NOME_PROFESSOR, COUNT(DISTINCT T.ID_DISCIPLINA)
FROM PROFESSOR P LEFT OUTER JOIN TURMA T
ON P.ID_PROFESSOR = T.ID_PROFESSOR
GROUP BY P.NOME_PROFESSOR;

--EX 2.14
SELECT CURSO.NOME_CURSO, COUNT(ID_TURMA)
FROM CURSO LEFT OUTER JOIN DISCIPLINA
ON CURSO.ID_CURSO = DISCIPLINA.ID_CURSO
LEFT OUTER JOIN TURMA
ON DISCIPLINA.ID_DISCIPLINA = TURMA.ID_DISCIPLINA
GROUP BY CURSO.NOME_CURSO;
