### IMPORTS
import sys
import numpy as np
import pandas as pd
import matplotlib
import matplotlib.pyplot as plt
import seaborn as sns
matplotlib.style.use('ggplot')


from sklearn import linear_model
from sklearn.ensemble import RandomForestClassifier
from sklearn.cross_validation import train_test_split

### FOR LISTING FUNCTION SIGNATURES
func_sigs = []

def add_func_sig(func_sigs, func_sig):
  func_sigs.append(func_sig)
  return func_sigs

def list_func_sig(func_sigs):
  if sys.argv[1] == 'functions':
    print func_sigs


### LOAD DATA
func_sigs = add_func_sig(func_sigs, "load_data(filename)")
def load_data(filename): 
  df = pd.read_csv(filename)
  print "SHAPE:", df.shape
  print "\nHEAD:\n", df.head(3)
  return df

### EXPLORATION
func_sigs = add_func_sig(func_sigs, "explore(df)")
def explore(df):
  print "INFO:\n", df.info()
  print "\nSTATS:\n", df.describe()

#df.plot(x='COL1', y='COL2')

#df.groupby('COL1')['COL2'].count()


### FIX NULLS
func_sigs = add_func_sig(func_sigs, "locate_null(df, col_name)")
def locate_null(df, col_name): 
  print df.loc[df[col_name].isnull(), col_name]

func_sigs = add_func_sig(func_sigs, "swap_null(df, col_name, value)")
def swap_null(df, col_name, value):
  df.loc[df[col_name].isnull(), col_name] = value
  return df

#data_to_keep = df[(df[col_name].notnull())]


### MODIFICATIONS
func_sigs = add_func_sig(func_sigs, "numericalize(df, col_names)")
def numericalize(df, col_names):
  for col_name in col_names:
    values = df[col_name].unique()
    num_values = [x for x in xrange(1,len(values)+1)]
    df[col_name] = df[col_name].map(dict(zip(values, num_values)))
  return df

func_sigs = add_func_sig(func_sigs, "drop_obj_cols(df)")
def drop_obj_cols(df):
  cols_to_drop = df.loc[:, df.dtypes == object].columns
  print "DROPPING:", cols_to_drop
  df = df.drop(cols_to_drop, axis=1)
  return df


### VISUALIZATION
#def bar_compare(col_filter, col_filter_value):

#df['SibSp'].value_counts().plot(kind='bar', color='black')
#df['SibSp'].value_counts().plot(kind='bar', color='gray')
#plt.show()

#plt.figure(figsize = (10,10))
#male_lived = lived[lived['Sex'] == 'male']
#female_lived = lived[lived['Sex'] == 'female']
#male_died = died[died['Sex'] == 'male']
#female_died = died[died['Sex'] == 'female']
#plt.scatter(male_lived['Age'], male_lived['Fare'], s=80, alpha=0.5, color='blue', marker='o')
#plt.scatter(female_lived['Age'], female_lived['Fare'], s=80, alpha=0.3, color='red', marker='o')
#plt.scatter(male_died['Age'], male_died['Fare'], s=80, alpha=0.5, color='blue', marker='x')
#plt.scatter(female_died['Age'], female_died['Fare'], s=80, alpha=0.9, color='red', marker='x')
#plt.show()


### LIST FUNCTION SIGNATURES 
list_func_sig(func_sigs)

