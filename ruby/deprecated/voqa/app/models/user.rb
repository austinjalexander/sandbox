class User < ActiveRecord::Base
  # Include default devise modules. Others available are:
  # :confirmable, :lockable, :timeoutable and :omniauthable
  devise :database_authenticatable, :registerable,
         :recoverable, :rememberable, :trackable, :validatable,
         :confirmable, :lockable, :timeoutable, :omniauthable

  has_many :questions
  has_many :answers

  before_validation :new_username, on: :create

  #validates :email, :password, :username, presence: true
  validates :email, :username, uniqueness: true

  private

    def new_username
      random = (('a'..'z').to_a + ('A'..'Z').to_a + ('0'..'9').to_a).shuffle[0,5].join
      self.username = "newbie-#{random}"
    end

end
