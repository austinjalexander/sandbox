require 'elasticsearch/model'

class Question < ActiveRecord::Base
  include Elasticsearch::Model
  include Elasticsearch::Model::Callbacks
  include ValidationHelpers
  belongs_to :user
  has_many :answers
  has_many :tags

  validates :title, :content, :user_id, presence: true, if: :user_id_is_valid?
  validates :title, :content, uniqueness: true

end

Question.import
