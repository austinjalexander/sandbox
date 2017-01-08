from imports import *

def modify_columns(ticker, normalize):
    df = pd.read_csv("quandl_data/{}.csv".format(ticker))
    df = df.drop('Adjusted Close', axis=1)
    
    df['50dravg'] = pd.rolling_mean(df['Close'], window=50)
    df['200dravg'] = pd.rolling_mean(df['Close'], window=200)

    if normalize == True:
        temp_df = df['Volume']
        df = df.drop('Volume', axis=1)
        std_df = df.std(axis=1, ddof=0)
        
        df['mean'] = df.mean(axis=1)
        df['std'] = std_df

        df['Open'] = (df['Open'] - df['mean']) / df['std']
        df['High'] = (df['High'] - df['mean']) / df['std']
        df['Low'] = (df['Low'] - df['mean']) / df['std']
        df['Close'] = (df['Close'] - df['mean']) / df['std']
        
        df['50dravg'] = (df['50dravg'] - df['mean']) / df['std']
        df['200dravg'] = (df['200dravg'] - df['mean']) / df['std']

        df = df.drop(['mean', 'std'], axis=1)

        df['Volume'] = temp_df

    df['OC%'] = (df['Close'] / df['Open']) - 1
    df['HL%'] = (df['High'] / df['Low']) - 1
    
    df['ticker'] = ticker

    df['label'] = df['OC%'].shift(-1)
    
    return df #df.loc[500:] # remove first 500 days


def import_data(tickers, binarize=False):
    normalize = False

    scale_volume = False

    # import data
    stock_df = pd.DataFrame()
    for ticker in tickers:
        if stock_df.empty:
            stock_df = modify_columns(ticker, normalize)
        else:
            stock_df = stock_df.append(modify_columns(ticker, normalize))
            #stock_df = pd.concat([stock_df, modify_columns(ticker, normalize)])
            #stock_df = pd.concat([stock_df, modify_columns(ticker, normalize)], verify_integrity=True)
            
    # scale volume
    if scale_volume == True:     
        stock_df['Volume'] = (stock_df['Volume'] - stock_df['Volume'].min()) / (stock_df['Volume'].max() - stock_df['Volume'].min())
        
        # log volume
        #stock_df['Volume'] = stock_df['Volume'].map(lambda x: np.log(x))

    #stock_df = stock_df.drop(['Open', 'High', 'Low', 'Close'], axis=1)

    # add bias
    #stock_df.insert(0, 'bias', 1.0)

    stock_df = stock_df.replace([np.inf, -np.inf], np.nan)

    # remove PPS > 5.0
    #stock_df = stock_df[stock_df['Open'] <= 5]

    # remove lower volume
    stock_df = stock_df[stock_df['Volume'] > 10**5]

    prediction_df = stock_df.copy()
    stock_df = stock_df.drop('ticker', axis=1)

    stock_df = stock_df.dropna()

    # binarize labels
    if binarize == True:
        stock_df['label'] = stock_df['label'].map(lambda x: 1 if x >= 0.05 else 0)

    return stock_df, prediction_df