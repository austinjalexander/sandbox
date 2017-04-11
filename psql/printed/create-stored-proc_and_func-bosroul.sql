--<< STORED PROCEDURE >>--
/* Add first user and admin to BosroulUser and BosroulAdmin tables */
/*
CREATE OR REPLACE
PROCEDURE AddFirstUserAndAdmin (
  a_email IN BosroulUser.email%TYPE,
  a_password IN BosroulUser.password%TYPE,
  a_registered_when IN BosroulUser.registered_when%TYPE,
  a_updated_when IN BosroulUser.updated_when%TYPE,
  
  a_bosroul_user_id_fk IN BosroulAdmin.bosroul_user_id%TYPE
)
IS
BEGIN

INSERT INTO BosroulUser (email,password,registered_when,updated_when) 
VALUES (a_email, a_password, a_registered_when, a_updated_when);

INSERT INTO BosroulAdmin (bosroul_user_id) VALUES (a_bosroul_user_id_fk);

END;
--*/

/*
BEGIN
  AddFirstUserAndAdmin('austinjalexander@gmail.com','JRsdfer32CA4JB', '13-Apr-2012 11:00:45 am','21-Sep-2013 01:32:20 pm', 1);
END;
--*/

/*********************************************************/
/***** USE INSERT SCRIPTS OR REAL DATA AT THIS POINT *****/
/*********************************************************/

--<< STORED FUNCTION >>--
--/*
SET SERVEROUTPUT ON;
--*/
/* count number of AM or PM decisions */
/*
CREATE OR REPLACE
FUNCTION countAMorPMdecisions(AM_or_PM CHAR)
RETURN NUMBER
IS num_AM_decisions NUMBER;
BEGIN
  SELECT COUNT(*) 
  INTO num_AM_decisions
  FROM (SELECT DecidesOn.decided_when
        FROM DecidesOn
        -- PSQL:
        --WHERE to_char(DecidesOn.decided_when, 'AM') LIKE '%AM' 
        -- ORACLE: 
        WHERE DecidesOn.decided_when LIKE AM_or_PM
        ORDER BY DecidesOn.decided_when) Decisions;
  RETURN(num_AM_decisions);
END;
--*/

--/*
DECLARE
num_AM_dec INTEGER;
num_PM_dec INTEGER;
total_dec INTEGER;
BEGIN
  SELECT DISTINCT countAMorPMdecisions('%AM%') INTO num_AM_dec FROM DecidesOn;
  SELECT DISTINCT countAMorPMdecisions('%PM%') INTO num_PM_dec FROM DecidesOn;
  total_dec := num_AM_dec + num_PM_dec;
  DBMS_OUTPUT.PUT_LINE('AM decisions: ' ||num_AM_dec);
  DBMS_OUTPUT.PUT_LINE('PM decisions: ' ||num_PM_dec);
  DBMS_OUTPUT.PUT_LINE('Total decisions: ' ||total_dec);
END;
--/
--*/
