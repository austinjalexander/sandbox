class CreateAnswers < ActiveRecord::Migration
  def change
    create_table :answers do |t|
      t.text :content
      t.belongs_to :user, index: true
      t.belongs_to :question, index: true

      t.timestamps null: false
    end

    add_index :answers, [:content, :user_id, :question_id], unique: true
  end
end
