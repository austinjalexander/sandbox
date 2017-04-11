--<< TRUNCATE TABLES >>--
/* 
access db:
  $ /usr/lib/postgresql/9.1/bin/psql -U austin -d bosroul 
  -- do this from appropriate directory 
  -- if using scripts
*/

-- to run: bpsimple=# \i truncate_tables-bosroul.sql

-- PSQL:
/*
TRUNCATE TABLE VotesOn CASCADE;
TRUNCATE TABLE Tags CASCADE;
TRUNCATE TABLE DecidesOn CASCADE;
TRUNCATE TABLE Suggestion CASCADE;
TRUNCATE TABLE BosroulAdmin CASCADE;
TRUNCATE TABLE BosroulUser CASCADE;
--*/

-- ORACLE:
--/*
TRUNCATE TABLE VotesOn;
TRUNCATE TABLE Tags;
TRUNCATE TABLE DecidesOn;
TRUNCATE TABLE BosroulAdmin;
DELETE Suggestion;
DELETE BosroulUser;
--*/
