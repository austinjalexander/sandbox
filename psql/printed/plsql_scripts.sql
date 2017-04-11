--<< PL/SQL SCRIPTS >>--

--/*
SET SERVEROUTPUT ON;
--*/

/* Test if user is an admin */
/*
DECLARE
is_admin INTEGER;
input_user_id INTEGER;
BEGIN

  input_user_id := &input_user_id;
  SELECT COUNT(*) INTO is_admin
  FROM BosroulAdmin 
  WHERE BosroulAdmin.bosroul_user_id = input_user_id;
  IF is_admin = 1 THEN
    DBMS_OUTPUT.PUT_LINE('User ' ||input_user_id|| ' is an admin');
  ELSE
     DBMS_OUTPUT.PUT_LINE('User ' ||input_user_id|| ' is not an admin');
  END IF;
END;
--*/

/* find and display gmail users */
--/*
DECLARE  
  GmailEmailList VARCHAR2(320);

  CURSOR BosroulUsersWithGmailEmails
  IS
    SELECT BosroulUser.email
    FROM BosroulUser
    WHERE BosroulUser.email LIKE '%@gmail.com%';
    
BEGIN

  FOR GmailUserEmailList
  IN BosroulUsersWithGmailEmails
  LOOP 
    DBMS_OUTPUT.PUT_LINE(GmailUserEmailList.email);
  END LOOP;
  
  SELECT BosroulUser.email 
  INTO GmailEmailList
  FROM BosroulUser
  WHERE email LIKE '%@gmail.com%';
  
  EXCEPTION 
  WHEN TOO_MANY_ROWS THEN 
    RAISE_APPLICATION_ERROR(-20001,'More than 1 Gmail users.');  
  WHEN NO_DATA_FOUND THEN 
    RAISE_APPLICATION_ERROR(-20002,'NO GMAIL USERS!');  
  
END;
--*/

/* user wants to deactivate account */
-- input needs to be a string enclosed in single quotes
-- e.g., 'austinja@bu.edu'
/*
DECLARE 
  status VARCHAR2(11) := 'DEACTIVATED';
  user_email VARCHAR2(320);
BEGIN

user_email := &user_email;

UPDATE BosroulUser
SET BosroulUser.email = status, BosroulUser.password = status
WHERE email = user_email;

END;
--*/
