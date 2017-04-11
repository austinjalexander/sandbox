--<< CREATE INDEXES >>--
--/*
/* find suggestions faster */
CREATE INDEX suggestion_name_caption_index
ON Suggestion(name,caption);

/* find tags faster */
CREATE INDEX tag_and_sugg_ids
ON Tags(tag_id,sugg_id);

/* find votes faster */
CREATE INDEX vote_and_sugg_ids
ON VotesOn(vote_id,sugg_id);
--*/