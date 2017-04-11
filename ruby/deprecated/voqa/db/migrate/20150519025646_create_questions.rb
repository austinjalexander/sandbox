class CreateQuestions < ActiveRecord::Migration
  def change
    create_table :questions do |t|
      t.string :title
      t.text :content
      t.belongs_to :user, index: true

      t.timestamps null: false
    end

    add_index :questions, [:title, :user_id, :content], unique: true
  end
end
