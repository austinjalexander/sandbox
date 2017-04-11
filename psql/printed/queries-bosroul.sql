--<< EXAMPLE SELECT QUERIES >>--
/* 
for psql: 
access db:
  $ /usr/lib/postgresql/9.1/bin/psql -U austin -d bosroul 
  -- do this from appropriate directory 
  -- if using scripts
*/

-- to run in psql: bosroul=# \i queries-bosroul.sql

/* List all users who have given suggestions (and list the suggestions) */
--/*
SELECT BosroulUser.bosroul_user_id AS "BosroulUser.bosroul_user_id", 
BosroulUser.email AS "BosroulUser.email", Suggestion.name AS "Suggestion.name"
FROM BosroulUser, Suggestion
WHERE BosroulUser.bosroul_user_id = Suggestion.bosroul_user_id
ORDER BY BosroulUser.bosroul_user_id;
--*/

/* Count number of suggestions submitted by individual users */
--/*
SELECT BosroulUser.bosroul_user_id AS "BosroulUser.bosroul_user_id",
COUNT(Suggestion.bosroul_user_id) AS "NumberOfSuggestions"
FROM BosroulUser, Suggestion
WHERE BosroulUser.bosroul_user_id = Suggestion.bosroul_user_id
GROUP BY BosroulUser.bosroul_user_id
ORDER BY BosroulUser.bosroul_user_id;
--*/

/* Count number of decisions made by users */
--/*
SELECT BosroulUser.bosroul_user_id AS "BosroulUser.bosroul_user_id", 
COUNT(DecidesOn.bosroul_user_id) AS "NumberOfDecisions"
FROM BosroulUser, DecidesOn
WHERE BosroulUser.bosroul_user_id = DecidesOn.bosroul_user_id
GROUP BY BosroulUser.bosroul_user_id
ORDER BY BosroulUser.bosroul_user_id;
--*/

/* List all suggestions where a decision was maybe */
--/*
SELECT Suggestion.sugg_id AS "Suggestion.sugg_id", 
Suggestion.name AS "Suggestion.name", DecidesOn.decision AS "DecidesOn.decision", 
DecidesOn.bosroul_user_id AS "DecidesOn.bosroul_user_id"
FROM Suggestion, DecidesOn
WHERE Suggestion.sugg_id = DecidesOn.sugg_id
AND DecidesOn.decision = 'maybe'
ORDER BY Suggestion.sugg_id, DecidesOn.bosroul_user_id;
--*/

/* List all suggestions and their tags */
--/*
SELECT Suggestion.sugg_id AS "Suggestion.sugg_id", 
Suggestion.name AS "Suggestion.name", Tags.word AS "Tags.word"
FROM Suggestion, Tags
WHERE Suggestion.sugg_id = Tags.sugg_id
ORDER BY Suggestion.sugg_id, Tags.word;
--*/

/* Suggestions and their votes */
--/*
SELECT Suggestion.sugg_id AS "Suggestion.sugg_id", 
Suggestion.name AS "Suggestion.name", VotesOn.vote AS "VotesOn.vote"
FROM Suggestion, VotesOn
WHERE Suggestion.sugg_id = VotesOn.sugg_id
ORDER BY Suggestion.sugg_id;
--*/

/* Count number of 'go' and 'no' votes on suggestions */
--/*
SELECT DISTINCT Suggestion.name AS "Suggestion.name", 
Suggestion.sugg_id AS "Suggestion.sugg_id",
COUNT(CASE WHEN VotesOn.vote = 'go' THEN 1 END) AS "NumberOfGoVotes",
COUNT(CASE WHEN VotesOn.vote = 'no' THEN 1 END) AS "NumberOfNoVotes"
FROM Suggestion, VotesOn
WHERE Suggestion.sugg_id = VotesOn.sugg_id
GROUP BY Suggestion.name, Suggestion.sugg_id
ORDER BY Suggestion.name;
--*/

/* Find suggestion(s) with the most 'go' votes */
--/*
SELECT DISTINCT VoteCount1.sugg_id AS "VotesOn.sugg_id", 
VoteCount1.GoCount AS "VotesOn.GoCount"
FROM (SELECT Suggestion.sugg_id, COUNT(*) AS GoCount
      FROM Suggestion, VotesOn
      WHERE Suggestion.sugg_id = VotesOn.sugg_id
      AND VotesOn.vote = 'go'
      GROUP BY Suggestion.sugg_id) VoteCount1, 
      (SELECT Suggestion.sugg_id, COUNT(*) AS GoCount
      FROM Suggestion, VotesOn
      WHERE Suggestion.sugg_id = VotesOn.sugg_id
      AND VotesOn.vote = 'go'
      GROUP BY Suggestion.sugg_id) VoteCount2
WHERE VoteCount1.GoCount > VoteCount2.GoCount
ORDER BY VoteCount1.sugg_id;
--*/

/* suggestions with same name but different captions (so possibly different places) */
--/*
SELECT DISTINCT Suggestion1.name AS "Suggestion.name", 
Suggestion1.caption AS "Suggestion1.caption", 
Suggestion2.caption AS "Suggestion2.caption"
FROM Suggestion Suggestion1, Suggestion Suggestion2
WHERE Suggestion1.name = Suggestion2.name
AND Suggestion1.caption < Suggestion2.caption -- <> or != would create duplicates
ORDER BY Suggestion1.name;
--*/

--<< EXAMPLE UPDATE STATEMENT >>--
/* user wants to update email address */
/*
UPDATE BosroulUser
SET email = 'austinja@bu.edu'
WHERE email = 'austinjalexander@gmail.com';
--*/

--<< EXAMPLE DELETE STATEMENT >>--
/* a user is no longer an admin */
/*
DELETE FROM BosroulAdmin
WHERE BosroulAdmin.bosroul_user_id = (SELECT BosroulUser.bosroul_user_id
                                      FROM BosroulUser
                                      WHERE BosroulUser.email = 'austinja@bu.edu');
--*/


