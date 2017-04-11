class QuestionsController < ApplicationController

  #before_action :set_question, only: [:show, :edit, :update, :destroy]
  before_action :set_question, only: [:show, :edit, :update]

  # GET /questions
  # GET /questions.json
  def index
    @questions = get_questions
    @question_new = Question.new
    @answers = Answer.all

    respond_to do |format|
      format.html
      format.js { @questions = get_questions }
    end

  end

  # GET /questions/1
  # GET /questions/1.json
  def show
    @question_new = Question.new

    @answers = Answer.includes(:user,:votes).where(question_id: @question.id)
    @answers = @answers.sort {|a,b| b.votes.sum(:value) <=> a.votes.sum(:value)}

    @answer = Answer.new
    @vote = Vote.new
  end

  def search
    @question_new = Question.new
    @answers = Answer.all
    if params[:q].present?
      @questions = get_questions.search(params[:q], size: 1000).records.order(created_at: :desc).paginate(page: params[:page], per_page: 20)
    else
      @questions = Question.none
    end
  end

  # GET /questions/new
  def new
    #@question = Question.new
  end

  # GET /questions/1/edit
  def edit
    @question_new = Question.new
  end

  # POST /questions
  # POST /questions.json
  def create
    @question = Question.new(question_params)
    @answers = Answer.all

    respond_to do |format|
      if @question.save
        #format.html { redirect_to @question, notice: 'Question was successfully created.' }
        format.js { @questions = get_questions }
        #format.json { render :show, status: :created, location: @question }
      else
        #format.html { render :new }
        #format.json { render json: @question.errors, status: :unprocessable_entity }
      end
    end
  end

  # PATCH/PUT /questions/1
  # PATCH/PUT /questions/1.json
  def update
    respond_to do |format|
      if @question.update(question_params)
        format.html { redirect_to @question, notice: 'Question was successfully updated.' }
        format.json { render :show, status: :ok, location: @question }
      else
        format.html { render :edit }
        format.json { render json: @question.errors, status: :unprocessable_entity }
      end
    end
  end

  # DELETE /questions/1
  # DELETE /questions/1.json
  def destroy
    @question.destroy
    respond_to do |format|
      format.html { redirect_to questions_url, notice: 'Question was successfully destroyed.' }
      format.json { head :no_content }
    end
  end

  def asked_by_me
    @questions = Question.where(user_id: current_user.id).order(created_at: :desc).paginate(page: params[:page], per_page: 20)
    @question_new = Question.new
    @answers = Answer.all
  end

  def answered_by_me
    @questions = Question.where(id: Answer.where(user_id: current_user.id).pluck(:question_id)).order(created_at: :desc).paginate(page: params[:page], per_page: 20)
    @question_new = Question.new
    @answers = Answer.all
  end

  private
    # Use callbacks to share common setup or constraints between actions.
    def set_question
      @question = Question.find(params[:id])
    end

    def get_questions
      Question.includes(:answers).order(created_at: :desc).paginate(page: params[:page], per_page: 20)
    end

    # Never trust parameters from the scary internet, only allow the white list through.
    def question_params
      params.require(:question).permit(:title, :content).merge(user_id: current_user.id)
    end
end
