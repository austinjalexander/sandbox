class Vote < ActiveRecord::Base

  include ValidationHelpers
  before_validation :answerer_is_not_voter?

  belongs_to :user
  belongs_to :answer

  validates :value, :answer_id, :user_id, presence: true, if: [:user_id_is_valid?, :answer_id_is_valid?]
  #validates :value, numericality: { only_integer: true }
  validates :value, inclusion: { in: [-1, 1] }
  validates_uniqueness_of :answer_id, { scope: :user_id }

end
