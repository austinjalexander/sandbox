class CreateVotes < ActiveRecord::Migration
  def change
    create_table :votes do |t|
      t.integer :value
      t.belongs_to :user, index: true
      t.belongs_to :answer, index: true

      t.timestamps null: false
    end

    add_index :votes, [:value, :user_id, :answer_id], unique: true
  end
end
