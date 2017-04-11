# This file should contain all the record creation needed to seed the database with its default values.
# The data can then be loaded with the rake db:seed (or created alongside the db with db:setup).
#
# Examples:
#
#   cities = City.create([{ name: 'Chicago' }, { name: 'Copenhagen' }])
#   Mayor.create(name: 'Emanuel', city: cities.first)


User.create(
  email: 'aja@gmail.com', 
  password: 'whynotAAA90'
)

User.create(
  email: 'mfd@gmail.com', 
  password: 'turkeylips22'
)

100.times do
  User.create(
    email: Faker::Internet.email, 
    password: Faker::Internet.password(min_length=8)
  )
end

100.times do
  Question.create(
    #title: Faker::Lorem.sentence, 
    title: Faker::Company.catch_phrase, 
    #content: Faker::Lorem.paragraph,
    content: Faker::Hacker.say_something_smart,
    user_id: Faker::Number.between(1,100)
  )
end

200.times do
  Answer.create(
    content: Faker::Hacker.say_something_smart,
    user_id: Faker::Number.between(1,100),
    question_id: Faker::Number.between(1,100)
  )
end

300.times do
  Vote.create(
    value: [-1,1].sample,
    user_id: Faker::Number.between(1,100),
    answer_id: Faker::Number.between(1,100)
  )
end


=begin

User.create([{ email: 'sara@somethingrandom.edu', password: '1234567890' },
             { email: 'austinjalexander@gmail.com', password: 'whynotAAA90' },
             { email: 'mark@somerandomthing.com', password: 'applesorange' },
             { email: 'cali@somerandomthing.com', password: 'sdkdferih34234235rfkdfkhsdf' },
             { email: 'nathan@somerandomthing.com', password: 'nathanthinkshescool' }])

Question.create([{ title: 'Portable Studio Solution', 
                   content: "I urgently need a portable studio solution. (I'm just talking hardware at the moment, not portable booths). Is the only option an iPad with twisted wave and a small portable USB mic, or is there something better/cheaper? And what portable mic would you suggest for auditions and even gigs if needed? Thanks for your help in advance!", 
                   user_id: 3 }])

Answer.create([{ content: "I use TW on my Macbook with my regular interface, M-audio fasttrack, and a AT2020 mic. But the AT2020 USB mic is said to have gret sound too. Then of course http://www.harlanhogan.com/portaboothArticle.shtml And Edge Studio has this: http://www.edgestudio.com/resource/voice-over-microphone", 
                 user_id: 2,
                 question_id: 1 }])

Question.create([{ title: 'Website Advice Question', 
                   content: "While getting prepared to re-enter the VO industry, I'm wondering if it's necessary to develop a website?", 
                   user_id: 1 }])

Question.create([{ title: 'IVR Recording File Types', 
                   content: "I've been asked to do some IVR recordings. I think that the files have to be a certain format other than wav or mp3...I think? I also need some direction on how to price it. Can anyone point me to a resource for this?", 
                   user_id: 2 }])
=end















