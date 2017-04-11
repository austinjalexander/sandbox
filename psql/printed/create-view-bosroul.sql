--<< CREATE VIEW >>--
/* View all user decisions on suggestions */
/*
CREATE VIEW AllUserDecOnSugg AS
SELECT BosroulUser.bosroul_user_id AS "BosroulUser.bosroul_user_id", 
Suggestion.sugg_id AS "Suggestion.sugg_id",
Suggestion.name AS "Suggestion.name", DecidesOn.decision AS "DecidesOn.decision"
FROM BosroulUser, Suggestion, DecidesOn
WHERE BosroulUser.bosroul_user_id = DecidesOn.bosroul_user_id
AND DecidesOn.sugg_id = Suggestion.sugg_id
ORDER BY BosroulUser.bosroul_user_id, Suggestion.sugg_id;
--*/

/* display all user decisions ordered by bosroul_user_id, then sugg_id */
/*
SELECT * 
FROM AllUserDecOnSugg;
--*/

/* display all user decisions ordered by sugg_id */
/*
SELECT * 
FROM AllUserDecOnSugg 
ORDER BY 2;
--*/