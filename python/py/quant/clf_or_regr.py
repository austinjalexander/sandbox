skb = []
best_learner = []
iteration_count = 0

#for k in xrange(1,X.shape[1]+1):
for k in [8]:
    
    print "\n", "#"*50, "\n"

    skb = SelectKBest(k=k)
    skb = skb.fit(X,y)
    new_X = skb.transform(X)

    t0 = time()

    clf_or_regr = "clf"
    pca = False

    ############################################################################

    if clf_or_regr == "regr":
        # add bias
        new_X = np.hstack((new_X, np.ones((new_X.shape[0], 1))))

        # single-class removal
        rows_to_remove = []
        for i in xrange(len(y)):
            if y[i] in classes_to_remove:
                rows_to_remove.append(i)

        new_X = np.delete(new_X, rows_to_remove, axis=0)
        y = np.delete(y, rows_to_remove)

    ############################################################################

    learner = []

    pipeline = []

    ############################################################################

    if clf_or_regr == "clf":
        learner = GaussianNB()
        learner = DecisionTreeClassifier()
        #learner = RandomForestClassifier()
        #learner = SVC()
        #learner = LogisticRegression()

    if clf_or_regr == "regr":
        learner = LinearRegression()
        #learner = Ridge()
        #learner = Lasso()
        #learner = BayesianRidge()
        #learner = SGDRegressor()
        #learner = SVR()
        #learner = DecisionTreeRegressor()
        #learner = GradientBoostingRegressor()

    ############################################################################

    if pca == False:
        pipeline = make_pipeline(learner)
    elif pca == True:
        pipeline = make_pipeline(RandomizedPCA(), learner)

    # cross validation    
    cv = StratifiedShuffleSplit(y, test_size=0.2, random_state=42)

    # tune parameters
    params = dict()

    # for PCA
    if pca == True:
        #params['randomizedpca__iterated_power'] = [1, 2, 3]
        #params['randomizedpca__n_components'] = [2, 4, 6, 8, 10]
        params['randomizedpca__random_state'] = [42]
        #params['randomizedpca__whiten'] = [True, False]

    ############################################################################

    if clf_or_regr == "clf":
        if str(learner)[0] == 'X':
            params['decisiontreeclassifier__criterion'] = ['gini', 'entropy']
            params['decisiontreeclassifier__max_features'] = ['auto', 'sqrt', 'log2', None]
            params['decisiontreeclassifier__class_weight'] = ['auto', None]
            params['decisiontreeclassifier__random_state'] = [42]

        if str(learner)[0] == 'S':
            # [2**x for x in np.arange(-15, 15+1, 3)]
            params['svc__C'] = [100] # np.logspace(-2, 10, 13)
            params['svc__gamma'] = [0.01] # np.logspace(-9, 3, 13)
            params['svc__random_state'] = [42]

    ############################################################################        

    grid_search = GridSearchCV(pipeline, param_grid=params, n_jobs=1, cv=cv)

    grid_search.fit(new_X, y)

    best_learner = grid_search.best_estimator_
    print best_learner
    print "\nscore: ", grid_search.best_score_

    best_learner = best_learner.fit(new_X,y)
    y_pred = best_learner.predict(new_X)

    ############################################################################

    if clf_or_regr == "clf":
        print "\nconfusion matrix:\n", "     FALSE   TRUE\n", "FALSE", confusion_matrix(y, y_pred)[0], "\nTRUE ", confusion_matrix(y, y_pred)[1]
        print "\n", classification_report(y, y_pred)

    print "\nprice data normalized:", normalize
    print "\nvolume scaled:", scale_volume
    print "\nbinarized:", binarize
    print "\nk =", k
    print "\nPCA:", pca
    print "\nminutes for learner to run:", round((time()-t0)/60.0, 3)
    print

    if iteration_count == 0:
        for i in xrange(len(stock_df.columns)):
            print stock_df.columns[i], np.round(skb.scores_[i], 2)
        iteration_count += 1
