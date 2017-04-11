--<< BosroulUser INSERTS >>--

/* table data generated from:
   http://www.generatedata.com
*/
/* psql:
access db:
  $ /usr/lib/postgresql/9.1/bin/psql -U austin -d bosroul 
  -- do this from appropriate directory 
  -- if using scripts
*/

-- to run: bosroul=# \i insert_data-BosroulUser.sql

-- BosroulUser
INSERT INTO BosroulUser (email,password,registered_when,updated_when) VALUES ('vel.sapien@nonquam.co.uk','JRE15KCA4JB', '15-Apr-2014 12:00:45 pm','23-Sep-2014 01:37:20 am');
INSERT INTO BosroulUser (email,password,registered_when,updated_when) VALUES ('Etiam@lacusUt.co.uk','MGJ60KIC3VC', '03-Aug-2013 08:00:46 pm','09-Apr-2014 08:47:12 pm');
INSERT INTO BosroulUser (email,password,registered_when,updated_when) VALUES ('lobortis@Maecenasornare.co.uk','CGH78DWK1GQ', '09-Dec-2013 02:49:59 am','09-Feb-2014 08:25:45 pm');
INSERT INTO BosroulUser (email,password,registered_when,updated_when) VALUES ('non.dapibus.rutrum@eleifendnon.org','SGH60ZDY3LG', '02-Sep-2013 05:14:11 pm','09-Oct-2014 11:28:22 am');
INSERT INTO BosroulUser (email,password,registered_when,updated_when) VALUES ('sed@nullavulputate.net','LSF92PXZ4ZX', '19-Aug-2013 11:08:58 am','05-Apr-2014 01:05:31 am');
-- ... --

--<< Suggestion INSERTS >>--

/* table data generated from:
   http://www.generatedata.com
*/
/* psql:
access db:
  $ /usr/lib/postgresql/9.1/bin/psql -U austin -d bosroul 
  -- do this from appropriate directory 
  -- if using scripts
*/

-- to run: bosroul=# \i insert_data-Suggestion.sql

-- Suggestion
INSERT INTO Suggestion (name,caption,date_end,made_when,bosroul_user_id) VALUES ('ante','enim. Suspendisse aliquet,','15-May-2014','01-Feb-2015 01:12:19 pm',74);
INSERT INTO Suggestion (name,caption,date_end,made_when,bosroul_user_id) VALUES ('pede','Integer','06-Dec-2013','21-Feb-2014 03:37:00 am',31);
INSERT INTO Suggestion (name,caption,date_end,made_when,bosroul_user_id) VALUES ('sodales','Phasellus in felis.','28-Apr-2014','10-Feb-2015 09:09:21 pm',50);
INSERT INTO Suggestion (name,caption,date_end,made_when,bosroul_user_id) VALUES ('risus quis','dui, nec tempus','19-Nov-2014','16-Apr-2013 12:09:03 pm',55);
INSERT INTO Suggestion (name,caption,date_end,made_when,bosroul_user_id) VALUES ('massa. Quisque','orci. Phasellus','24-Sep-2014','27-Dec-2014 08:33:11 pm',55);
-- ... --

--<< DecidesOn INSERTS >>--

/* table data generated from:
   http://www.generatedata.com
*/
/* psql:
access db:
  $ /usr/lib/postgresql/9.1/bin/psql -U austin -d bosroul 
  -- do this from appropriate directory 
  -- if using scripts
*/

-- to run: bosroul=# \i insert_data-DecidesOn.sql

-- DecidesOn
INSERT INTO DecidesOn (decision,decided_when,bosroul_user_id,sugg_id) VALUES ('next','08-Jul-2013 01:45:43 am',65,75);
INSERT INTO DecidesOn (decision,decided_when,bosroul_user_id,sugg_id) VALUES ('next','20-Jul-2014 09:15:20 am',30,79);
INSERT INTO DecidesOn (decision,decided_when,bosroul_user_id,sugg_id) VALUES ('maybe','03-Jul-2014 10:43:04 am',28,59);
INSERT INTO DecidesOn (decision,decided_when,bosroul_user_id,sugg_id) VALUES ('maybe','12-Mar-2013 12:42:31 pm',100,84);
INSERT INTO DecidesOn (decision,decided_when,bosroul_user_id,sugg_id) VALUES ('next','08-Apr-2014 03:22:57 am',55,50);
-- ... --

--<< Tags INSERTS >>--

/* table data generated from:
   http://www.generatedata.com
*/
-- line 53 violates the uniqueness constraint for testing purposes
/* psql
access db:
  $ /usr/lib/postgresql/9.1/bin/psql -U austin -d bosroul 
  -- do this from appropriate directory 
  -- if using scripts
*/

-- to run: bosroul=# \i insert_data-Tags.sql

-- Tags
INSERT INTO Tags (word,tagged_when,bosroul_user_id,sugg_id) VALUES ('non','27-Mar-2013 09:15:56 am',34,96);
INSERT INTO Tags (word,tagged_when,bosroul_user_id,sugg_id) VALUES ('ac','13-Jun-2013 07:30:47 am',23,100);
INSERT INTO Tags (word,tagged_when,bosroul_user_id,sugg_id) VALUES ('massa.','07-Jun-2013 03:56:00 pm',68,8);
INSERT INTO Tags (word,tagged_when,bosroul_user_id,sugg_id) VALUES ('Vestibulum','24-May-2014 09:55:14 pm',37,11);
INSERT INTO Tags (word,tagged_when,bosroul_user_id,sugg_id) VALUES ('nibh','24-Aug-2014 09:46:01 pm',82,91);
-- ... --

--<< VotesOn INSERTS >>--

/* table data generated from:
   http://www.generatedata.com
*/
-- line 93 violates the uniqueness constraint for testing purposes
/* psql
access db:
  $ /usr/lib/postgresql/9.1/bin/psql -U austin -d bosroul 
  -- do this from appropriate directory 
  -- if using scripts
*/

-- to run: bosroul=# \i insert_data-VotesOn.sql

-- VotesOn
INSERT INTO VotesOn (vote,voted_when,bosroul_user_id,sugg_id) VALUES ('no','23-Oct-2014 03:45:35 am',18,22);
INSERT INTO VotesOn (vote,voted_when,bosroul_user_id,sugg_id) VALUES ('go','06-Dec-2013 01:45:45 pm',14,99);
INSERT INTO VotesOn (vote,voted_when,bosroul_user_id,sugg_id) VALUES ('no','26-Mar-2014 02:39:08 am',60,91);
INSERT INTO VotesOn (vote,voted_when,bosroul_user_id,sugg_id) VALUES ('no','13-Sep-2014 05:10:35 am',13,76);
INSERT INTO VotesOn (vote,voted_when,bosroul_user_id,sugg_id) VALUES ('no','29-Dec-2013 08:56:48 pm',88,60);