module QuestionsHelper

  def current_user_question_count 
    num_of_current_user_questions = Question.where(user_id: current_user[:id]).count
  end

  def current_user_answer_count 
    num_of_current_user_answers = Answer.where(user_id: current_user[:id]).count
  end

end
