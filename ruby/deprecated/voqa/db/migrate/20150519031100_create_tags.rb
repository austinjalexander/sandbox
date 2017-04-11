class CreateTags < ActiveRecord::Migration
  def change
    create_table :tags do |t|
      t.string :name
      t.belongs_to :user, index: true
      t.belongs_to :question, index: true

      t.timestamps null: false
    end
  end
end
