module ValidationHelpers

  def user_id_is_valid?
    User.find(self.user_id)
  end

  def answer_id_is_valid?
    Answer.find(self.answer_id)
  end

  def answerer_is_not_voter?
    Answer.find(self.answer_id).user_id != self.user_id
  end

end
