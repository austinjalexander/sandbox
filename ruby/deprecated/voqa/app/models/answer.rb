class Answer < ActiveRecord::Base
  include ValidationHelpers
  belongs_to :user
  belongs_to :question
  has_many :votes

  validates :content, :question_id, :user_id, presence: true, if: :user_id_is_valid?
  validates :content, uniqueness: true

end
