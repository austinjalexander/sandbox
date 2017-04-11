--<< DROP TABLES >>--
/* for psql:
access db:
  $ /usr/lib/postgresql/9.1/bin/psql -U austin -d bosroul 
  -- do this from appropriate directory 
  -- if using scripts
*/

-- to run: bpsimple=# \i drop_tables-bosroul.sql

--/*
DROP TABLE VotesOn;
DROP TABLE Tags;
DROP TABLE DecidesOn;
DROP TABLE Suggestion;
DROP TABLE BosroulAdmin;
DROP TABLE BosroulUser;
--*/
