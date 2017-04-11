--<< POSTGRESQL CREATE TABLES >>--
/*
create db:
  # su - austin
  $ /usr/lib/postgresql/9.1/bin/createdb bosroul

access db:
  $ /usr/lib/postgresql/9.1/bin/psql -U austin -d bosroul 
  -- do this from appropriate directory 
  -- if using scripts
*/

-- to run: bosroul=# \i create_tables-bosroul.sql

--/*
CREATE DOMAIN decision_type AS varchar(5)
  CHECK (VALUE = 'maybe' OR VALUE = 'next');
  -- domain values needed to use ''

CREATE DOMAIN vote_type AS varchar(2)
  CHECK (VALUE = 'go' OR VALUE = 'no');
--*/

--/*
CREATE TABLE BosroulUser (
  bosroul_user_id serial PRIMARY KEY,
  email varchar(320) NOT NULL UNIQUE,
  password varchar(60) NOT NULL,
  registered_when timestamp NOT NULL,
  updated_when timestamp NOT NULL
);

CREATE TABLE BosroulAdmin (
  admin_id serial PRIMARY KEY,
  bosroul_user_id integer REFERENCES BosroulUser(bosroul_user_id)
);

CREATE TABLE Suggestion (
  sugg_id serial PRIMARY KEY,
  name varchar(20) NOT NULL,
  caption varchar(50) NOT NULL,
  date_end date,
  made_when timestamp NOT NULL,
  bosroul_user_id integer REFERENCES BosroulUser(bosroul_user_id)
);

CREATE TABLE DecidesOn (
  dec_id serial PRIMARY KEY,
  decision decision_type NOT NULL,
  decided_when timestamp NOT NULL,
  bosroul_user_id integer REFERENCES BosroulUser(bosroul_user_id),
  sugg_id integer REFERENCES Suggestion(sugg_id)
);

CREATE TABLE Tags (
  tag_id serial PRIMARY KEY,
  word varchar(10) NOT NULL,
  tagged_when timestamp NOT NULL,
  bosroul_user_id integer REFERENCES BosroulUser(bosroul_user_id),
  sugg_id integer REFERENCES Suggestion(sugg_id),
  UNIQUE (bosroul_user_id, sugg_id)
);

CREATE TABLE VotesOn (
  vote_id serial PRIMARY KEY,
  vote vote_type NOT NULL,
  voted_when timestamp NOT NULL,
  bosroul_user_id integer REFERENCES BosroulUser(bosroul_user_id),
  sugg_id integer REFERENCES Suggestion(sugg_id),
  UNIQUE (bosroul_user_id, sugg_id)
);
--*/

