--<< CREATE TRIGGER >>--

/* Limit the number of tags per Suggestion to five */
/*
CREATE OR REPLACE TRIGGER LMTTagsPerSuggestionToFive
  BEFORE INSERT OR UPDATE ON Tags
  FOR EACH ROW
DECLARE
num_of_tags INTEGER;
tag_limit INTEGER := 5;
BEGIN
  SELECT COUNT(*) INTO num_of_tags
  FROM Tags 
  WHERE :new.sugg_id = Tags.sugg_id;
  IF num_of_tags >= tag_limit THEN
    RAISE_APPLICATION_ERROR(-20000,'Suggestion already has 5 tags');
  ELSE
     RETURN;
  END IF;
END;
--*/

/* Test trigger */
-- will succeed:
/*
INSERT INTO Tags (word,tagged_when,bosroul_user_id,sugg_id) 
VALUES ('tacos!','29-Apr-2014 10:49:33 pm',1,24);
--*/
-- will fail:
--/*
INSERT INTO Tags (word,tagged_when,bosroul_user_id,sugg_id) 
VALUES ('spicy!','29-Apr-2014 10:49:33 pm',1,25);
--*/