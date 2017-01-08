from imports import *

def avg_clf_train(X, y, k, C, gamma, stock_df): 

    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

    print "k =", k
    skb = SelectKBest(k=k)
    skb.fit(X_train, y_train)
    X_train = skb.transform(X_train)
    X_test = skb.transform(X_test)

    for i in xrange(len(stock_df.columns)):
        print stock_df.columns[i], np.round(skb.scores_[i], 2)
    
    print

    clf_or_regr = "clf"

    t0 = time()

    #learners = [GaussianNB(), DecisionTreeClassifier(class_weight='auto', criterion='gini', max_depth=None, max_features='auto', max_leaf_nodes=None, min_samples_leaf=1, min_samples_split=2, min_weight_fraction_leaf=0.0, random_state=42, splitter='best'), SVC(C=C, gamma=gamma), LogisticRegression()]
    
    learners = [DecisionTreeClassifier(class_weight='auto', criterion='gini', max_depth=None, max_features='auto', max_leaf_nodes=None, min_samples_leaf=1, min_samples_split=2, min_weight_fraction_leaf=0.0, random_state=42, splitter='best')]

    for i in xrange(len(learners)):

        ############################################################################     

        #learner = GaussianNB()
        #learner = DecisionTreeClassifier()
        #learner = RandomForestClassifier()
        #learner = SVC()
        #learner = LogisticRegression()

        learners[i] = learners[i].fit(X_train,y_train)

        y_pred = learners[i].predict(X_test)

        ############################################################################

        print learners[i]
        print learners[i].score(X_test,y_test)

        if clf_or_regr == "clf":
            print "\nconfusion matrix:\n", "     FALSE   TRUE\n", "FALSE", confusion_matrix(y_test, y_pred)[0], "\nTRUE ", confusion_matrix(y_test, y_pred)[1]
            print "\n", classification_report(y_test, y_pred)

        #print "\nprice data normalized:", normalize
        #print "\nvolume scaled:", scale_volume
        #print "\nbinarized:", binarize
        #print "\nPCA:", pca
        print "\nminutes for learner to run:", round((time()-t0)/60.0, 3)
        print

    return skb, learners
